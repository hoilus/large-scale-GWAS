/* Author: Liang Hong <lianghong80@gmail.com>
   modified on 10/24/2017
*/

#include <iostream>
#include <stdexcept>
#include "vcf.h"

using namespace std;

int usage() {
    cerr << "Usage: ./test_readingvcf ./test.vcf" << endl;
    return 1;
}

int main(int argc, char* argv[]) {
    if(argc == 2) {
        htsFile *test_bcf = NULL;
        bcf_hdr_t *test_header = NULL;
        bcf1_t *test_record = bcf_init();
        test_bcf = bcf_open(argv[1], "r");
        if(test_bcf == NULL) {
            throw runtime_error("Unable to open file.");
        }
        test_header = bcf_hdr_read(test_bcf);
        if(test_header == NULL) {
            throw runtime_error("Unable to read header.");
        }
        cout << "chromosome\tposition\tnum_alleles" << endl;
        while(bcf_read(test_bcf, test_header, test_record) == 0) {
            cout << bcf_hdr_id2name(test_header, test_record->rid) << "\t" <<
                         test_record->pos << "\t" <<
                         test_record->n_allele << "\t" <<
                         endl;
        }
        bcf_hdr_destroy(test_header);
        bcf_destroy(test_record); 
        bcf_close(test_bcf);
    } else {
        return usage();
    }
    return 0;
}
