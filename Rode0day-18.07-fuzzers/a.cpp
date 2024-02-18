#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cassert>
#include <random>
#include <cstdint>

using namespace std;

class FileMutator {
  using V = std::vector<uint8_t>;

  public:
  
  private:
    void Append(V *to, const V &from) {
      to->insert(to->end(), from.begin(), from.end());
    }
    void PrintHex(const V &v, size_t max_n) {
        for (size_t i = 0; i < max_n && i < v.size(); i++) {
          std::cerr << "0x" << std::hex << (unsigned)v[i] << " " << std::dec;
        }
        std::cerr << std::endl;
      }
    uint32_t Read4(std::istream &in) {
        uint32_t res = 0;
        in.read((char *)&res, sizeof(res));
        return res;
      }
      uint32_t ReadInteger(std::istream &in) {
        return __builtin_bswap32(Read4(in));
      }
      static uint32_t Type(const char *tagname) {
        uint32_t res;
        assert(strlen(tagname) == 4);
        memcpy(&res, tagname, 4);
        return res;
      }
    
      void WriteInt(std::ostream &out, uint32_t x) {
        x = __builtin_bswap32(x);
        out.write((char *)&x, sizeof(x));
      }

};

extern "C" size_t LLVMFuzzerCustomMutator(uint8_t *Data, size_t Size,
                                          size_t MaxSize, unsigned int Seed) {
}

extern "C" size_t LLVMFuzzerCustomCrossOver(const uint8_t *Data1, size_t Size1,
                                            const uint8_t *Data2, size_t Size2,
                                            uint8_t *Out, size_t MaxOutSize,
                                            unsigned int Seed) {
  }
