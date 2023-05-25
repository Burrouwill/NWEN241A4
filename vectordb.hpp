#ifndef VECTORDB_HPP
#define VECTORDB_HPP

#include "abstractdb.hpp"
#include <vector>

class VectorDbTable : public nwen::AbstractDbTable {
public:
    int rows() const override;
    const nwen::movie* get(int index) const override;
    bool add(const nwen::movie& m) override;
    bool update(unsigned long id, const nwen::movie& m) override;
    bool remove(unsigned long id) override;

private:
    std::vector<nwen::movie> table;
};

#endif // VECTORDB_HPP
