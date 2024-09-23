use std::collections::BTreeMap;

const LIMIT: u32 = 10000;

fn main() {
    let mut amicables: Vec<u32> = Vec::new();

    for i in 2..LIMIT {
        for j in i..LIMIT {
            if are_amicable(i, j) {
                amicables.push(i);
                amicables.push(j);
                println!("{} {}", i, j);
            }
        }
    }

    println!("{}", amicables.into_iter().sum::<u32>());
}

#[inline]
fn are_amicable(n: u32, m: u32) -> bool {
    // test if:
    // a. n and m are not the same
    // b. the sum of the factors in n (excluding n itself) are equal to m, and vice versa
    n != m  && get_factors(n).into_iter().sum::<u32>() == m && get_factors(m).into_iter().sum::<u32>() == n
}

const factors_cache: BTreeMap<u32, Vec<u32>> = BTreeMap::new();

// note that function does not include the number itself in it's return value
fn get_factors(n: u32) -> Vec<u32> {
    if factors_cache.contains_key(&n) {
        return factors_cache.get(&n).unwrap().to_vec();
    }

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

    factors_cache.insert(n.clone(), factors.clone());

    factors
}

