#include <iostream>
#include <fstream>

int main()
{
	std::ofstream creatFile("in.txt");
    creatFile << 5 << std::endl;
	for (int i = 1; i < 5 + 1; i++) {
        creatFile << i << " ";
	}
    creatFile << std::endl << 6 << std::endl;
	for (int i = 10; i <= 60; i += 10) {
        creatFile << i << " ";
	}

    std::ifstream inFile("in.txt");
    int sizeN, sizeM, temp;
    inFile >> sizeN;
    int* arr = new int[sizeN];
    if (inFile.is_open()) {
        for (int i = 0; i < sizeN; i++) {
            inFile >> temp;
            arr[i] = temp;
        }
    }
    else {
        return 1;
    }
    inFile >> sizeM;
    int* arr2 = new int[sizeM];
    if (inFile.is_open()) {
        for (int i = 0; i < sizeM; i++) {
            inFile >> temp;
            arr2[i] = temp;
        }
    }
    else {
        return 1;
    }
    inFile.close();

    std::ofstream outFile("out.txt");

    outFile << sizeM << std::endl;
    outFile << arr2[sizeM - 1] << " ";
    for (int i = 0; i < sizeM - 1; i++) {
        temp = arr2[i];
        outFile << temp << " ";
    }
    outFile << std::endl << sizeN << std::endl;
    for (int i = 1; i < sizeN; i++) {
        temp = arr[i];
        outFile << temp << " ";
    }
    outFile << arr[0] << " ";

    std::cout << "completed";
    outFile.close();
    delete[] arr;
    delete[] arr2;
    return 0;
}