#include <iostream>
#include <vector>

// Function to find the nth element from a list
int nthElement(int n, const std::vector<int>& list) {
    if (n >= list.size()) {
        std::cerr << "Error: Index out of range." << std::endl;
        return -1; // or throw an exception, depending on your desired error handling
    }
    return list[n];
}

int main() {
    std::vector<int> myList = {1, 2, 3, 4, 5}; // Example list
    int n = 2; // Example nth element to find

    int result = nthElement(n, myList);
    if (result != -1) {
        std::cout << "The " << n << "th element is: " << result << std::endl;
    }

    return 0;
}
