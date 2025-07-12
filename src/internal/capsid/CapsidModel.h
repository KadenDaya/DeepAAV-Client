#include "CapsidUnit.h"

class CapsidModel {
    public:
        void generate(int n=60) {

            for (int i =0; i<n; i++) {
                CapsidUnit unit;
                unit.id = i;
                unit.amino_acid_seq = "AKRT";
                units.push_back(unit);
            }
        }
        void saveCapsid(const std::string& path);
        void loadCapsid(const std::string& path);
        
        // Unit Tests
        bool isValidSize() {
            return units.size() == 60;
        }
        bool hasUniqueIDs() {
            for (int i = 0; i < units.size(); i++) {
                for (int j = i + 1; j < units.size(); j++) {
                    if (units[i].id == units[j].id) {
                        return false;
                    }
                }
            }
            return true;
        }
    private:
        std::vector<CapsidUnit> units;
}