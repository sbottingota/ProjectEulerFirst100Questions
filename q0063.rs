const BASE_LIMIT: u128 = 16;
const POWER_LIMIT: u32 = 31;

fn main() {
    let mut count: usize = 0;

    for base in 1..BASE_LIMIT {
        for power in 1..POWER_LIMIT {
            let result = base.pow(power);
            if result.ilog10() + 1 == power {
                count += 1;
                // println!("{}^{}={}, {}", base, power, result, result.ilog10());
            }
        }
    }

    println!("{}", count);
}

