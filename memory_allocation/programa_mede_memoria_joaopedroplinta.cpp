#include <iostream>
#include <fstream>
#include <sys/resource.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

struct Person {
    std::string name;
    int age;
};

int main() {
    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);

    std::cout << "Uso de memória antes..." << std::endl;
    std::cout << "MT: " << r_usage.ru_maxrss << " KB" << std::endl;

    srand(time(nullptr));

    std::ofstream outputFile("results.csv"); // Abre o arquivo para escrita
    outputFile << "NumRecords;ElapsedTime;MaxRSS;CPUTimeUser;CPUTimeSystem;Addresses\n"; // Escreve cabeçalho

    for (int numRecords = 10000; numRecords <= 1000000; numRecords += 10000) {
        std::cout << "Alocando " << numRecords << " registros..." << std::endl;

        clock_t startTime = clock();
        clock_t cpuStartTime = clock();

        Person *people = new Person[numRecords];
        std::vector<std::string> addresses; // Vetor para armazenar os endereços

        for (int i = 0; i < numRecords; ++i) {
            std::string address = std::to_string(reinterpret_cast<std::uintptr_t>(&people[i])); // Converte o endereço para string
            addresses.push_back(address); // Adiciona ao vetor
            people[i].name = std::string(rand() % 401 + 100, ' ');
            people[i].age = rand() % 60 + 1;
        }

        clock_t endTime = clock();
        double elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
        clock_t cpuEndTime = clock();

        getrusage(RUSAGE_SELF, &r_usage);
        std::cout << "MT após alocar " << numRecords << " registros: " << r_usage.ru_maxrss << " KB" << std::endl;
        std::cout << "Tempo de execução para alocar: " << elapsedTime << " segundos" << std::endl;

        double userTime = r_usage.ru_utime.tv_sec + r_usage.ru_utime.tv_usec / 1000000.0;
        double sysTime = r_usage.ru_stime.tv_sec + r_usage.ru_stime.tv_usec / 1000000.0;

        // Escrever os dados no arquivo CSV
        outputFile << numRecords / 10000 << ";"
                   << elapsedTime << ";"
                   << r_usage.ru_maxrss << ";"
                   << userTime << ";"
                   << sysTime << ";" << &people << "\n";

        delete[] people;
    }

    outputFile.close();

    getrusage(RUSAGE_SELF, &r_usage);
    std::cout << "Uso de memória após a conclusão: " << r_usage.ru_maxrss << " KB" << std::endl;

    return 0;
}
