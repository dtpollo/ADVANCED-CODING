#include "spellcheck.h"
#include <algorithm>
#include <cctype>
#include <vector>
#include <iterator>
#include <ranges>  

namespace rv = std::ranges::views;

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred) {
    std::vector<Iterator> results;
    std::vector<bool> matches;
    
    std::transform(
        begin, end, std::back_inserter(matches),
        [&](const auto& item) { return pred(item); }
    );
    
    for (auto it = begin; it != end; ++it) {
        if (pred(*it)) results.push_back(it);
    }
    results.push_back(end);
    
    return results;
}

Corpus tokenize(const std::string& source) {
    Corpus tokens;
    
    auto positions = find_all(source.begin(), source.end(), ::isalnum);

    for (size_t i = 0; i < positions.size() - 1; ++i) {
        auto begin = positions[i];
        auto end = positions[i+1];
        
        if (begin != end) {
            tokens.emplace(source, begin, end);
        }
    }
    
    return tokens;
}

std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
    std::set<Mispelling> mispellings;
    
    auto misspelled = source | std::views::filter([&](const Token& t) {
        return dictionary.find(t.content) == dictionary.end();
    });
    
    for (const auto& token : misspelled) {
        Mispelling m{token, {}};
        for (const auto& word : dictionary) {
            if (levenshtein(token.content, word) <= 1) {
                m.suggestions.insert(word);
            }
        }
        mispellings.insert(m);
    }
    
    return mispellings;
}