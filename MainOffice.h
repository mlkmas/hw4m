#pragma once
#include "Branch.h"
#include <map>
#include <string>
#include <stdexcept>
#include <functional>

class MainOffice {
private:
    std::map<std::string, Branch> branches;

    // Private constructor for Singleton
    MainOffice() {}

public:
    // Delete copy constructor and assignment operator
    MainOffice(const MainOffice&) = delete;
    MainOffice& operator=(const MainOffice&) = delete;

    // Public method to access the singleton instance
    static MainOffice& getInstance() {
        static MainOffice instance;
        return instance;
    }

    void addBranch(const std::string& location, int capacity);

    void removeBranch(const std::string& location);

    Branch& getBranch(const std::string& location);

    void printBranchesByLocation(std::function<void(const Branch&)> printFunc) const;

    void printBranchesByValue(std::function<void(const Branch&)> printFunc) const;

    // Exception classes
    class ExistingBranchInsertError : public std::runtime_error {
    public:
        ExistingBranchInsertError() : std::runtime_error("Branch with this location already exists") {}
    };

    class NonExistingBranchRemoveError : public std::runtime_error {
    public:
        NonExistingBranchRemoveError() : std::runtime_error("Branch with this location does not exist") {}
    };

    class NonExistingBranchRetrieveError : public std::runtime_error {
    public:
        NonExistingBranchRetrieveError() : std::runtime_error("Branch with this location does not exist") {}
    };
};
