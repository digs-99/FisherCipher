#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int readFile(string filename){
    ifstream f(*argv)
    char flag;
    string rawText;
    while(f >> flag){
         if(flag == EOF){
             return rawText;
         }
         rawText += flag;
    }
}

int errCheck(string f, string k){
    ifstream inFile(f);
    ifstream inKey(k)
    if(!inFile){
        cerr << "In File does not exist. Please provide a file that does exist.\n"
        exit(1);
    }
    if(!inKey){
        cerr << "KeyFile does not exist. Please provide a valid keyfile.\n"
        exit(1);
    }
    inFile.close();
    inKey.close();
}


int blockEncrypt(string plainText, string key, string outputfile){
    //check for pad
    int pad = 8 - (plainText.length()%8)
    for(int i = 0; i<pad; i++){
        plainText += static_cast<char>(0x80);
    }
    //encrypt
    string encryptedText = "";
    int iterations = (plainText.length()/8);
    for(c=0; c<iterations; c++){
        string substring = plainText.substr((8*c), 8);
        for(int j = 0; j<8; j++){
            encryptedText += ((substring.at(j))^(key.at(j)));
        }
    }
    //swap
    int keyCount = 0;
    int start = 0;
    int end = encryptedText.length()-1;
    while(start < end){
        if(keyCount == 8){
            keyCount = 0; //resets keycount every 8 chars
        }
        if(((key.at(keyCount))%2) == 1){
            temp = encryptedText.at(start);
            encryptedText[start] = encryptedText.at(end);
            encryptedText[end] = temp;
            start++;
            end--;
        }
        else{
            start++
        }
        keyCount++;
    }
    //output file
    osstream out(outputfile);
    out << encryptedText;
    o.close();
}

int blockDecrypt(string encryptedText, string key, string outputfile){
    //swap
    int keyCount = 0;
    int start = 0;
    int end = encryptedText.length()-1;
    while(start < end){
        if(keyCount == 8){
            keyCount = 0; //resets keycount every 8 chars
        }
        if(((key.at(keyCount))%2) == 1){
            temp = encryptedText.at(start);
            encryptedText[start] = encryptedText.at(end);
            encryptedText[end] = temp;
            start++;
            end--;
        }
        else{
            start++
        }
        keyCount++;
    }
    //decrypt
    string plainText = "";
    int iterations = (encryptedText.length()/8);
    for(c=0; c<iterations; c++){
        string substring = encryptedText.substr((8*c), 8);
        for(int j = 0; j<8; j++){
            plainText += ((substring.at(j))^(key.at(j)));
        }
    }
    //remove padding
    while(plainText.back() == static_cast<char>(0x80)){
        plainText.pop_back();
    }
    ofstream o(outputfile);
    o << plainText;
    o.close();
}

int blockCipher(string filename, string keyfile, char mode, string outputfile){
    string filename = *argv[2];
    string keyfile = *argv[4];
    errCheck(filename, keyfile);
    ifstream k(keyfile);
    string key = "";
    k >> key;
    if(key.length() != 8){
        cerr << "Key is not 64bits. Key must be 64 bits for block cypher.\n"
        exit(1);
    }
    string rawText = readFile(filename);
    if(mode == 'E'){
        blockEncrypt(rawText, key, outputfile);
    } else if(mode == 'D'){
        blockDecrypt(rawText, key, outputfile);
    }else{
        cerr << "Fifth Paramater must be either 'E' or 'D'. Please provide correct paramater."
    }



}

int streamCipher(string filename, string keyfile,string outputfile){
    ifstream f(filename);
    ifstream k(keysfile);
    ofstream o(outputfile);
    char c;
    char key;
    while(file >> c){
        k >> key;
        if(key == EOF){
            key.clear();
            k.seekg(0, ios::beg);
            k >> key;
        }
        o << static_cast<char>(c^key);
    }
    f.close();
    k.close();
    o.close();
    return 0;


}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        cerr << "Error invalid number of Arguments. Correct Format is Char, input filename, output filename, keyfile, mode]\n";
        exit(1);
    }
    string filename = *argv[2];
    string keyfile = *argv[4];
    string outputfile = *argv[3];
    errCheck(filename, keyfile);
    if (*argv[1] == 'B') {
        string mode = *argv[5];
        if (mode.length() != 1){
            cerr << "Fifth Parameter should be one char, Please provide a valid Char.\n"
            exit(1);
        }
        char mode = string.at(0);
        blockcipher(filename, keyfile, mode, outputfile)
    } else if (*argv[1] == 'S') {
        streamCipher(filename, keyfile, outputfile);
    } else{
        cerr << "Error invalid operation. Please enter either 'B' or 'S'.\n";
    }
}