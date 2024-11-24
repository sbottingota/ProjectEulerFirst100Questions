const TARGET: u32 = 1_000_000;
const N_DIGITS: usize = 10;

#[inline]
fn has_repeated_digits(mut n: u32) -> bool {
    let mut digits_found: Vec<u32> = Vec::new();
    for _ in 0..N_DIGITS {
        let d1 = n % 10;

        for d2 in &digits_found {
            if d1 == *d2 {
                return true;
            }
        }

        digits_found.push(d1);
        n /= 10;
    }

    false
}

fn main() {
    let mut n: u32 = 100_000_000;
    let mut i: u32 = 0;

    while i != TARGET {
        loop {
            n += 1;
            // print!("\rChecked {:0>10}", n);
            if !has_repeated_digits(n) {
                break;
            }
        }

        // println!("Found {:0>10}", n);
        i += 1;
    }

    println!("{:0>10}", n);
}

