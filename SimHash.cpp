#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// Хэш-функция
bitset<64> hashFunction(int value) {
    hash<int> hash;
    return bitset<64>(hash(value));
}

// SimHash
bitset<64> computeSimHash(const vector<int>& inputSet) {
    bitset<64> simHash;

    for (int value : inputSet) {
        bitset<64> hashValue = hashFunction(value);
        simHash ^= hashValue;
    }

    return simHash;
}

// Функция для вычисления схожести
double calculateSimHashSimilarity(const bitset<64>& hash1, const bitset<64>& hash2) {
    bitset<64> xorResult = hash1 ^ hash2;
    int differingBits = xorResult.count();
    return 1.0 - static_cast<double>(differingBits) / 64.0;
}

int main() {

    vector<int> set1 = {1, 1, 1, 1};
    vector<int> set2 = {2, 1, 1, 1};

    bitset<64> simHash1 = computeSimHash(set1);
    bitset<64> simHash2 = computeSimHash(set2);

    double similarity = calculateSimHashSimilarity(simHash1, simHash2);

    // Результат
    cout << "Similarity: " << similarity << endl;

    return 0;
}
