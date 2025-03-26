#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>


void displayInventory(const std::map<std::string, int>& inventory) {
std::cout << "Current Inventory:\n";
for (const auto& item : inventory) {
std::cout << item.first << ": " << item.second << " in stock\n";
}
std::cout << std::endl;
}


void displayCategories(const std::set<std::string>& productCategories) {
std::cout << "Product Categories:\n";
for (const auto& category : productCategories) {
std::cout << "- " << category << "\n";
}
std::cout << std::endl;
}

void processOrders(std::queue<std::string>& orders) {
std::cout << "Processing Orders:\n";
while (!orders.empty()) {
std::cout << "Processing " << orders.front() << std::endl;
orders.pop();
}
std::cout << std::endl;
}


void processRestocks(std::stack<std::pair<std::string, int>>& restocks) {
std::cout << "Processing Restocks:\n";
while (!restocks.empty()) {
auto item = restocks.top();
std::cout << "Restocking " << item.second << " units of " << item.first << std::endl;
restocks.pop();
}
std::cout << std::endl;
}


void displayCart(const std::vector<std::string>& customerCart) {
std::cout << "Items in customer cart:\n";
for (const auto& item : customerCart) {
std::cout << "- " << item << "\n";
}
std::cout << std::endl;
}

int main() {
// Task 1
std::map<std::string, int> inventory;
inventory["Laptop"] = 5;
inventory["Mouse"] = 20;
inventory["Keyboard"] = 10;
displayInventory(inventory);

// Task 2
std::set<std::string> productCategories;
productCategories.insert("Electronics");
productCategories.insert("Accessories");
productCategories.insert("Peripherals");
displayCategories(productCategories);

// Task 3
std::queue<std::string> orders;
orders.push("Order#1: Laptop");
orders.push("Order#2: Mouse");
orders.push("Order#3: Keyboard");
processOrders(orders);

// Task 4
std::stack<std::pair<std::string, int>> restocks;
restocks.push({"Mouse", 10});
restocks.push({"Laptop", 2});
restocks.push({"Keyboard", 5});
processRestocks(restocks);

// Task 5
std::vector<std::string> customerCart;
customerCart.push_back("Laptop");
customerCart.push_back("Mouse");
customerCart.push_back("Keyboard");
displayCart(customerCart);

return 0;
}