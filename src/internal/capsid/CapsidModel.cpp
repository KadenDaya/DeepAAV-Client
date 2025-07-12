#include "CapsidModel.h"

void CapsidModel::saveCapsid(std::string path) {
    std::ofstream file(path);
    file << "// Capsid Saving Format v1.0" << std::endl;
    file << "// Developed with love by Kaden Daya and Alexander Blake" << std::endl;
    file << "" << std::endl;
    file << "CSF v1.0" << std::endl;
    file << "" << std::endl;
    file << "UNITS " + std::to_string(units.size()) << std::endl;
    file << "" << std::endl;
    for (int i = 0; i < units.size(); i++) {
        file << "UNIT " + std::to_string(units[i].id);
        file << " " + units[i].amino_acid_seq << std::endl;
    }
    file << "" << std::endl;
    
    switch (capsid.function) {
        case x:
            payload_function = "SpCas9";
            break;
        case y:
            payload_function = "gRNA";
            break;
        case z:
            payload_function = "HDR";
    
    file << "PAYLOAD FUNCTION " + payload_function << std::endl;
    file << "" << std::endl;
    file << "PAYLOAD START" << std::endl;
    file << ">ITR" << std::endl;
    file << std::to_string(capsid.itr.seq) << std::endl;
    switch (capsid.function) {
        case x:
            file << ">SpCas9" << std::endl;
            file << std::to_string(capsid.spcas9.seq) << std::endl;
            break;
        case y:
            file << ">gRNA" << std::endl;
            file << std::to_string(capsid.grna.seq) << std::endl;
            break;
        case z:
            file << ">HDR" << std::endl;
            file << std::to_string(capsid.hdr.seq) << std::endl;
            break;
    }
    file << ">ITR" << std::endl;
    file << std::to_string(capsid.itr.seq) << std::endl;
    file << "PAYLOAD END" << std::endl;
    file.close();
}
void loadCapsid(std::string path) {

}
