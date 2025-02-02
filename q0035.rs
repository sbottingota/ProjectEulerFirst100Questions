const LIMIT: u32 = 1_000_000;

fn is_prime(n: u32) -> bool {
    if n < 2 {
        false
    } else if n == 2 {
        true
    } else if n % 2 == 0 {
        false
    } else {
        // check every odd number up to, and including, n
        let mut i: u32 = 3;
        while i * i <= n {
            if n % i == 0 {
                return false;
            }

            i += 2;
        }

        true
    }
}

fn is_circular_prime(n: u32) -> bool {
    if !is_prime(n) {
        return false;
    }

    let mut digits: Vec<u32> = n.to_string().chars().map(|c| c.to_digit(10).unwrap()).collect();

    // cycle through every possible combination of the digits of n, seeing if it is prime
    for _ in 0..digits.len() - 1 {
        digits.rotate_right(1);

        // turn the vec of digits into a number
        let mut m = 0;
        for digit in &digits {
            m *= 10;
            m += digit;
        }

        if !is_prime(m) {
            return false;
        }
    }

    true
}

fn main() {
    // count the number of circular primes from 2 to LIMIT

    let mut count: u32 = 0;

    for i in 2..LIMIT {
        if is_circular_prime(i) {
            count += 1;
        }
    }

    println!("{}", count);
}

