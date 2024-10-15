#include <iostream>
#include <string>
#include <vector>

class HashTable {
private:
    std::vector<std::string> table;
    int size;

    int hash(const std::string& s) {
        int sum = 0;
        for (int i = 0; i < s.length(); ++i) {  
            sum += (std::toupper(s[i]) - 'A' + 1);
        }
        return sum % size;
    }

public:
    HashTable(int z) : size(z), table(z, "") {
        if (z <= 0) {
            throw std::invalid_argument("Size of hash table must be positive");
        }
    }

    void insert(const std::string& s) {
        int index = hash(s);
        while (!table[index].empty()) {
            index = (index + 1) % size;
        }
        table[index] = s;
    }

    void print() {
        for (int i = 0; i < table.size(); ++i) { 
            std::cout << (table[i].empty() ? "NULL" : table[i]) << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int Z, n;
    std::cin >> Z >> n;

    try {
        HashTable hashTable(Z);

        for (int i = 0; i < n; ++i) {
            std::string word;
            std::cin >> word;
            hashTable.insert(word);
        }

        hashTable.print();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
