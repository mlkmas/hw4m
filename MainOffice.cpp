#include "MainOffice.h"
#include <iostream>
#include <algorithm>

void MainOffice::addBranch(const std::string& location, int capacity) {
    auto result = branches.try_emplace(location, location, capacity);
    if (!result.second) {
        throw ExistingBranchInsertError();
    }
}

void MainOffice::removeBranch(const std::string& location) {
    auto it = branches.find(location);
    if (it == branches.end()) {
        throw NonExistingBranchRemoveError();
    }
    branches.erase(it);
}

Branch& MainOffice::getBranch(const std::string& location) {
    auto it = branches.find(location);
    if (it == branches.end()) {
        throw NonExistingBranchRetrieveError();
    }
    return it->second;
}

void MainOffice::printBranchesByLocation(std::function<void(const Branch&)> printFunc) const {
    for (const auto& [location, branch] : branches) {
        printFunc(branch);
    }
}

void MainOffice::printBranchesByValue(std::function<void(const Branch&)> printFunc) const {
    std::vector<std::pair<std::string, Branch>> branchVector(branches.begin(), branches.end());

    std::sort(branchVector.begin(), branchVector.end(), [](const auto& a, const auto& b) {
        int aValue = 0, bValue = 0;

        for (const auto& item : a.second.getCatalog()) {
            aValue += item->getPrice();
        }

        for (const auto& item : b.second.getCatalog()) {
            bValue += item->getPrice();
        }

        if (aValue == bValue) {
            return a.first < b.first;
        }
        return aValue > bValue;
        });

    for (const auto& [location, branch] : branchVector) {
        printFunc(branch);
    }
}
