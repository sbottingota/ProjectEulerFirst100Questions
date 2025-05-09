const DIGIT_LIMIT: u32 = 1_000_000;

fn main() {
    let mut digits = 0_u32;

    let mut digit_product = 1_u32;

    for i in 1_u32.. {
        let prev_digits = digits;
        digits += i.ilog10() + 1;
        
        // if a power of 10 has been passed
        if prev_digits == 0 || digits.ilog10() - prev_digits.ilog10() == 1 {
            digit_product *= i
                .to_string()
                .chars()
                .nth(i.ilog10() as usize - digits as usize + 10_usize.pow(digits.ilog10())) // offset index to get relevant digit
                .unwrap()
                .to_digit(10)
                .unwrap();
        }

        if digits >= DIGIT_LIMIT {
            break;
        }
    }

    println!("{}", digit_product);
}

