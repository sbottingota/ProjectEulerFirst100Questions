// need to calculate the last 10 digits of the number MULTIPLIER * 2^EXPONENT + 1

const MULTIPLIER: u64 = 28433;
const EXPONENT: u64 = 7830457;
const N_DIGITS: u32 = 10;

fn main() {
    let mut n = MULTIPLIER;

    for _ in 0..EXPONENT {
        n *= 2;
        n %= 10_u64.pow(N_DIGITS);
    }

    n += 1;

    println!("{:010}", n);
}

