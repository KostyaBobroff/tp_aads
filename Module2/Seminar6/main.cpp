#include <iostream>
#include <vector>
class OutBitStream {
public:
    OutBitStream();
    void WriteBit(unsigned char bit);
    void WriteByte(unsigned char byte);
    const std::vector<unsigned char>& GetBuffer() const;
private:
    std::vector<unsigned char> buffer;
    int bitsCount;

};


OutBitStream::OutBitStream():bitsCount(0) {}
void OutBitStream::WriteBit(unsigned char bit) {
    if (bitsCount == buffer.size() * 8) {
        buffer.push_back(0);
    }
    if (bit == 1) {
        buffer[buffer.size() - 1] |= 1 << (bitsCount % 8);
    }
    bitsCount++;
}

void OutBitStream::WriteByte(unsigned char byte) {
    if(bitsCount % 8 == 0) {
        buffer.push_back(byte);
        bitsCount += 8;
        return;
    } else{
        buffer[buffer.size() - 1] |= byte << (bitsCount % 8 );
        buffer.push_back(byte >> (8 - bitsCount % 8));
    }

    bitsCount += 8;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
