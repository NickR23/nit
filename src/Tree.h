#include <vector>

#include <types.h>

#pragma once

namespace nit {

constexpr std::string DIRMODE = "40000";
constexpr std::string FILEMODE = "100644";

struct TreeEntry {
    std::string name;
    std::string mode;  // DIRMODE or FILEMODE. TODO maybe make this an enum?
    std::string hash; // blob hash for files and tree hash for directories
};

/** 
 * Trees represent a snapshot of a tree of directories.
 */
class Tree {
public:
    Tree() = default;

    void addEntry(const TreeEntry& entry);
    // Returns the serialization of the Tree's contents
    std::vector<uint8_t> serialize() const;
    void updateHash();
    static Tree deserialize(const std::vector<uint8_t>& data);
    const std::vector<TreeEntry>& getEntries() const;
    const std::string& getHash() const;

private:
    std::vector<TreeEntry> entries;
    std::string hash;
};

}