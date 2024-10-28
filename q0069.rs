const LIMIT: usize = 1e6 as usize;

// compute the number of numbers less than n that are coprime with n
// function adapted from https://www.geeksforgeeks.org/eulers-totient-function/#gfg-tab-generated-14
fn n_coprime(mut n: u32) -> u32 {
    let mut res = n;

    // consider all prime factors of n and subtract their multiples from res
    let mut i = 2;
    while i*i <= n {
        if n % i == 0 {
            while n % i == 0 {
                n /= i;
            }
            res -= res / i;
        }
        
        i += 1;
    }

    // if n has a prime factor greater than sqrt(n) there can be at most one prime factor
    if n > 1 {
        res -= res / n;
    }

    res

    /*
    let mut count: u32 = 1; // 1 is coprime to everything

    for i in 2..n {
        if gcd(i, n) == 1 {
            count += 1
        }
    }

    count
    */
}

fn main() {
    // find the input to n_coprime where i / n_coprime(i) is maximized
    let mut best_input: usize = 0;
    let mut best_output: f64 = 0.0;
    for i in 2..=LIMIT {
        let out = i as f64 / n_coprime(i as u32) as f64;
        if out > best_output {
            best_input = i;
            best_output = out;
        }
    }

    println!("{}", best_input);
}

