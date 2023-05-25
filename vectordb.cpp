#include "vectordb.hpp"

/**
 * Implementation of rows()
 */
int VectorDbTable::rows() const {
    // Return no.of rows
    return table.size();
}

/**
 * Implementation of get()
 */
const nwen::movie* VectorDbTable::get(int index) const {
    if (index >= 0 && index < table.size()) {
        // If valid row number given as args --> Return the movie at the index
        return &table[index];
    }
    // If invalid row, return null pointer
    return nullptr;
}

/**
 * Implementation of add()
 */
bool VectorDbTable::add(const nwen::movie& m) {
    // Check if a record with the same ID already exists
    for (const auto& movie : table) {
        if (movie.id == m.id) {
            return false; // ID already exists, return false without adding the record
        }
    }

    // No existing record with the same ID, add the new record to the table
    table.push_back(m);
    return true; // Return true to indicate successful addition
}

/**
 * Implementation of update()
 */
bool VectorDbTable::update(unsigned long id, const nwen::movie& m) {
    // For each movie in the table
    for (auto& movie : table) {
        // If movie id == id we are looking for
        if (movie.id == id) {
            // Set update the movie
            movie = m;
            return true;
        }
    }
    // We couldnt find the movie, return false
    return false;
}

/**
 * Implementation of remove()
 */
bool VectorDbTable::remove(unsigned long id) {
    // For each entry in the table
    for (auto it = table.begin(); it != table.end(); ++it) {
        // If the movie id == id we are looking for
        if (it->id == id) {
            // Remove the entry from the vector
            table.erase(it);
            return true;
        }
    }
    // We coudlnt find it
    return false;
}
