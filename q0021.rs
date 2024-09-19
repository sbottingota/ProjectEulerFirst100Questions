const LIMIT: u32 = 3000;

fn main() {
    let mut amicables: Vec<u32> = Vec::new();

    for i in 2..LIMIT {
        // println!("{:?}", get_factors(i));
        if is_amicable(i) {
            amicables.push(i);
            println!("{}", i);
        }
    }

    println!("{}", amicables.into_iter().sum::<u32>());
}

// test if n is amicable with any number up to LIMIT
fn is_amicable(n: u32) -> bool {
    for m in 2..LIMIT {
        if are_amicable(n, m) {
            return true;
        }
    }

    false
}

#[inline]
fn are_amicable(n: u32, m: u32) -> bool {
    // test if:
    // a. n and m are not the same
    // b. the sum of the factors in n (excluding n itself) are equal to m, and vice versa
    n != m  && get_factors(n).into_iter().sum::<u32>() == m && get_factors(m).into_iter().sum::<u32>() == n
}

// note that function does not include the number itself in it's return value
fn get_factors(n: u32) -> Vec<u32> {
    let mut factors: Vec<u32> = vec![1];
    let upper_bound = (n as f64).sqrt() as u32 + 1;
    for i in 2..upper_bound {
        if n % i == 0 {
            factors.push(i);
            if n / i != i {
                factors.push(n / i);
            }
        }
    }

    factors
}

