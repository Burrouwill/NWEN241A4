
#include "abstractdb.hpp"
#include <fstream>

/**
 * Implementation of saveCSV()
 */ 
bool nwen::AbstractDbTable::saveCSV(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file.is_open()) {
        return false; // File cannot be opened for writing
    }

    // Empty the file
    file.close();
    file.open(filename, std::ofstream::out | std::ofstream::trunc);

    if (!file.is_open()) {
        return false; // File cannot be emptied
    }

    int rowCount = rows();
    for (int i = 0; i < rowCount; ++i) {
        const movie* m = get(i);
        if (m == nullptr) {
            continue;
        }

        file << m->id << ",\"" << m->title << "\"," << m->year << ",\"" << m->director << "\"" << std::endl;

        if (file.fail()) {
            file.close();
            return false; // Error encountered while writing to the file
        }
    }

    file.close();
    return true; // Successful writing to the file
}