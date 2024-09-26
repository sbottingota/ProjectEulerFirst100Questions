fn main() {
    let mut num_product: u32 = 1;
    let mut denom_product: u32 = 1;

    for numerator in 10..100 {
        for denominator in numerator + 1..100 {
            if is_example_fraction(numerator, denominator) {
                num_product *= numerator;
                denom_product *= denominator;
                println!("{}/{}", numerator, denominator);
            }
        }
    }

    println!("{} {}", num_product, denom_product);
    println!("{:?}", simplify_fraction(num_product, denom_product));
}

fn simplify_fraction(mut numerator: u32, mut denominator: u32) -> (u32, u32) {
    // inefficient, but does the job
    for i in (2..numerator).rev() {
        if numerator % i == 0 && denominator % i == 0 {
            numerator /= i;
            denominator /= i;
        }
    }

    (numerator, denominator)
}

fn is_example_fraction(numerator: u32, denominator: u32) -> bool {
    assert!(numerator >= 10 && numerator < 100, "'numerator' must have exactly 2 digits");
    assert!(denominator >= 10 && denominator < 100, "'denominator' must have exactly 2 digits");

    if numerator % 10 == 0 && denominator % 10 == 0 || numerator == denominator {
        return false; // trivial
    }

    let num_tens: u32 = numerator / 10;
    let num_units: u32 = numerator % 10;
    let denom_tens: u32 = denominator / 10;
    let denom_units: u32 = denominator % 10;

    (num_tens == denom_tens && are_fracs_eq(num_units, denom_units, numerator, denominator))
    || (num_tens == denom_units && are_fracs_eq(num_units, denom_tens, numerator, denominator))
    || (num_units == denom_tens && are_fracs_eq(num_tens, denom_units, numerator, denominator))
    || (num_units == denom_units && are_fracs_eq(num_tens, denom_tens, numerator, denominator))
}

#[inline]
fn are_fracs_eq(num1: u32, denom1: u32, num2: u32, denom2: u32) -> bool {
    denom1 != 0 && denom2 != 0  && num1 as f64 / denom1 as f64 == num2 as f64 / denom2 as f64
}

