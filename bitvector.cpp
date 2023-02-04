#include <iostream>

namespace Mybitvector {
    struct Bitvector {
	 int length;
    	 long long* arr;
    };

    struct Bitvector* create_bitvector(int bits) {
   	 struct Bitvector* obj = new struct Bitvector; 
         int length = bits / (8 * sizeof(long long)) + (bits % (8 * sizeof(long long)) != 0);
    	 obj -> length = length;
    	 long long* array = new long long[length];
    	 obj -> arr = array ; 
    	 return obj;
    }

    void set(struct Bitvector* b, int index) {
     	 int n_th_byte = index / (8 * sizeof(long long));
    	 long long mask = 1 << (index - n_th_byte * 8 * sizeof(long long));
     	 b -> arr[n_th_byte] = b -> arr[n_th_byte] | mask;
     	 return;
    }

    void reset(struct Bitvector* b, int index) {
   	 int n_th_byte = index / (8 * sizeof(long long));
    	 long long mask = 1 << (index - n_th_byte * 8 * sizeof(long long));
     	 b -> arr[n_th_byte] = b -> arr[n_th_byte] & ~mask;
     	 return;
    }

    int get_bit(struct Bitvector* b, int i) {
   	int n_th_byte = i / (8 * sizeof(long long));
  	int bit_status = (b -> arr[n_th_byte]) >> (i - n_th_byte *( 8 * sizeof(long long))) & 1;
 	if(bit_status) {
           return 1;
    	}
    	else {
           return 0;
    	}
    }
  
    void destroy(struct Bitvector* b) {
    	delete[] (b -> arr);
    	delete b;
    }
  
};

int main() {
    int length = 0;
    int n = 0;
    int position = 0;
    std::cout << "Please input the length of bitvector " << std::endl;
    std::cin >> length;
    Mybitvector::Bitvector* vec = Mybitvector::create_bitvector(length);
    std::cout << "Please input the number of positions you want to change to 1 " << std::endl;
    std::cin >> n;
    std::cout << "Please input the positions of bitvector you want to change to 1 " << std::endl;
    for(int i = 0; i < n; i++) {
        std::cin >> position;
        Mybitvector::set(vec, position);
    }
    std::cout << "Please input the number of positions you want to change to 0 " << std:: endl;
    std::cin >> n;
    std::cout << "Please input the positions of bitvector you want to change to 0 " << std::endl;
    for(int i = 0; i < n; i++) {
        std::cin >> position;
       Mybitvector::reset(vec, position);
    }
    
    std::cout << "The output is " << std::endl;
    for(int i = length - 1; i >= 0; i--) {
    std::cout <<  Mybitvector::get_bit(vec, i);
    } 
    destroy(vec);
    return 0;
}

