#ifndef ABSTRACTDB_HPP
#define ABSTRACTDB_HPP

#include <string>

using namespace std;

namespace nwen{

 struct movie {
        unsigned long id;
        char title[50];
        unsigned short year;
        char director[50];
    };

class AbstractDbTable {
public:
    virtual int rows() const = 0;
    virtual const nwen::movie* get(int index) const = 0;
    virtual bool add(const nwen::movie& m) = 0;
    virtual bool update(unsigned long id, const nwen::movie& m) = 0;
    virtual bool remove(unsigned long id) = 0;
    bool loadCSV(const std::string& filename);
    bool saveCSV(const std::string& filename) const;
    virtual ~AbstractDbTable() {}
};

}

#endif // ABSTRACTDB_HPP
