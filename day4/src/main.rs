// Santa is mining some coin-currency: AdventCoins
// He uses te MD5 hash function
//
// In this exercise:
// Come up with a lowest positive number when paired with
// the secret key, the hash output starts with five zeros

// How does the MD5 work:
// - Pad bits to the input to the input string to make sure the
//   the total size is 64 bits less than multiple of 512
// - Add the length of the initial input string to get the
//   length of multiple of 512
// - Initialize 4 different MD buffers (A,B,C and D), init as follows:
//   A = 01 23 45 67
//   B = 89 ab cd ef
//   C = fe dc ba 98
//   D = 76 54 32 10

fn main() {
    println!("Hello, world!");
}
