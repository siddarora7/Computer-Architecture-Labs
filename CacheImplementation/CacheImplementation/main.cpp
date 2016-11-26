/*
 Cache Simulator
 Level one L1 and level two L2 cache parameters are read from file (block size, line per set and set per cache).
 The 32 bit address is divided into tag bits (t), set index bits (s) and block offset bits (b)
 s = log2(#sets)   b = log2(block size)  t=32-s-b
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include <bitset>

using namespace std;
//access state:
#define NA 0 // no action
#define RH 1 // read hit
#define RM 2 // read miss
#define WH 3 // Write hit
#define WM 4 // write miss




struct config{
    int L1blocksize;
    int L1setsize;
    int L1size;
    int L2blocksize;
    int L2setsize;
    int L2size;
};

/* you can define the cache class here, or design your own data structure for L1 and L2 cache
 class cache {
 
 }
 */

//class cache{
//    int cacheBlocks[(cacheconfig.L1size/cacheconfig.L1blocksize)];};
//
//class cacheways{
//    cache caches
//};
//
//    for (int i=0; i<cacheconfig.L2setsize;i++){
//        int cache2a[(cacheconfig.L2size/(cacheconfig.L2blocksize*cacheconfig.L2setsize)]
//
//    }
//    int cache2a[(cacheconfig.L2size/(cacheconfig.L2blocksize*cacheconfig.L2setsize)]
//    int cache2b[(cacheconfig.L2size/(cacheconfig.L2blocksize*cacheconfig.L2setsize)]
//    int cache2c[(cacheconfig.L2size/(cacheconfig.L2blocksize*cacheconfig.L2setsize)]
//    int cache2d[(cacheconfig.L2size/(cacheconfig.L2blocksize*cacheconfig.L2setsize)]
//
//
//};
class create_cache

{

    
    
};


int main(int argc, char* argv[]){
    
    
    cout<<"1"<<endl;
    config cacheconfig;
    ifstream cache_params;
    string dummyLine;
    cache_params.open("cacheconfig.txt");
    while(!cache_params.eof())  // read config file
    {

        cache_params>>dummyLine;
        cache_params>>cacheconfig.L1blocksize;
        cout<<cacheconfig.L1blocksize;
        cache_params>>cacheconfig.L1setsize;
        cache_params>>cacheconfig.L1size;
        cache_params>>dummyLine;
        cache_params>>cacheconfig.L2blocksize;
        cache_params>>cacheconfig.L2setsize;
        cache_params>>cacheconfig.L2size;

    }
    
    cout<<"2"<<endl;

    
    // Implement by you:
    // initialize the hirearch cache system with those configs
    // probably you may define a Cache class for L1 and L2, or any data structure you like
    
    
    
    
    int L1AcceState =0; // L1 access state variable, can be one of NA, RH, RM, WH, WM;
    int L2AcceState =0; // L2 access state variable, can be one of NA, RH, RM, WH, WM;
    
    
    ifstream traces;
    ofstream tracesout;
    string outname;
    outname = "trace.out";
    
    traces.open("trace.txt");
    tracesout.open(outname.c_str());
    
    string line;
    string accesstype;  // the Read/Write access type from the memory trace;
    string xaddr;       // the address from the memory trace store in hex;
    unsigned int addr;  // the address from the memory trace store in unsigned int;
    bitset<32> accessaddr; // the address from the memory trace store in the bitset;
    int count=0;
    if (traces.is_open()&&tracesout.is_open()){
        while (getline (traces,line)){   // read mem access file and access Cache
            
            istringstream iss(line);
            if (!(iss >> accesstype >> xaddr)) {break;}
            stringstream saddr(xaddr);
            saddr >> std::hex >> addr;
            accessaddr = bitset<32> (addr);
            for (count; count<1;count++){
                std::cout<<accessaddr;}
            
            // access the L1 and L2 Cache according to the trace;
//            if (accesstype.compare("R")==0)
//                
//            {
//                //Implement by you:
//                // read access to the L1 Cache,
//                //  and then L2 (if required),
//                //  update the L1 and L2 access state variable;
//                
//                
//                
//                
//                
//                
//                
//            }
//            else
//            {
//                //Implement by you:
//                // write access to the L1 Cache,
//                //and then L2 (if required),
//                //update the L1 and L2 access state variable;
//                
//                
//                
//                
//                
//                
//            }
//            
//            
            
//            tracesout<< L1AcceState << " " << L2AcceState << endl;  // Output hit/miss results for L1 and L2 to the output file;
//            
            
        }
        traces.close();
        tracesout.close();
    }
    else cout<< "Unable to open trace or traceout file ";
    
    //For L1 cache
    int L1_no_of_blocks= ( ( (cacheconfig.L1size) * 1024) / ( (cacheconfig.L1blocksize) * (cacheconfig.L1setsize )) ) ;
    
    int L1_no_of_index_bits= log2(L1_no_of_blocks);
    
    int L1_no_of_tag_bits = 32 - L1_no_of_index_bits;
    
    // For L2 cache
    
    
    int L2_no_of_blocks= ( ( (cacheconfig.L2size) * 1024) / ( (cacheconfig.L2blocksize) * (cacheconfig.L2setsize )) ) ;
    
    int L2_no_of_index_bits= log2(L2_no_of_blocks);
    
    int L2_no_of_tag_bits = 32 - L2_no_of_index_bits;
    
    //pass the index bits and tag bits and the address to the structure
    
    
    
    
    
    
    
    return 0;
}
