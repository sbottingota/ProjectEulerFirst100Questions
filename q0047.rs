const N_CONSECUTIVE: usize = 4;
const N_FACTORS: usize = N_CONSECUTIVE;

fn main() {
    let mut i: u32 = 2;
    let mut numbers: Vec<u32> = Vec::new();
    let mut factors: Vec<Vec<u32>> = Vec::new();

    loop {
        // println!("{:?}", get_prime_factors(i));
        let factor = get_prime_factors(i);
        numbers.push(i);
        factors.push(factor.clone());

        if numbers.len() == N_CONSECUTIVE {
            if factors.iter().any(|v| v.len() != N_FACTORS) {
                numbers.remove(0);
                factors.remove(0);
            } else {
                let mut found = true;
                for i in 0..N_CONSECUTIVE - 1 {
                    if !are_mutually_exclusive(&factors[i], &factors[i + 1]) {
                        numbers.remove(0);
                        factors.remove(0);
                        found = false;
                        break;
                    }
                }

                if found {
                    println!("{}", numbers[0]);
                    return;
                }
            }
        }
        i += 1;
    }
}

fn are_mutually_exclusive(u: &Vec<u32>, v: &Vec<u32>) -> bool {
    for item in u {
        if v.contains(&item) {
            return false;
        }
    }

    true
}

fn get_prime_factors(n: u32) -> Vec<u32> {
    get_factors(n).into_iter().filter(|&n| is_prime(n)).collect()
}

fn is_prime(n: u32) -> bool {
    if n < 2 {
        return false;
    } else if n == 2 {
        return true;
    } else if n % 2 == 0 {
        return false;
    }

    let sqrt_n: u32 = (n as f64).sqrt() as u32;

    let mut i: u32 = 3;
    while i <= sqrt_n {
        if n % i == 0 {
            return false;
        }
        i += 2;
    }

    true
}

fn get_factors(n: u32) -> Vec<u32> {
    let mut factors: Vec<u32> = vec![1];
    factors.push(n);
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

