const LIMIT: u32 = 1_000_00;

// https://en.wikipedia.org/wiki/Pentagonal_number#Tests_for_pentagonal_numbers
fn is_pentagonal(n: u32) -> bool {
    let n = n as f64;

    (((24.*n + 1.).sqrt() + 1.) / 6.).fract() == 0.
}

fn nth_pentagonal(n: u32) -> u32 {
    n * (3*n - 1) / 2
}

fn main() {
    let mut best_n = u32::MAX;
    let mut best_m = 0_u32;

    for i in 1..LIMIT {
        for j in 1..LIMIT {
            if i == j {
                continue;
            }

            let n = nth_pentagonal(i);
            let m = nth_pentagonal(j);

            if is_pentagonal(n + m) && is_pentagonal(n.abs_diff(m)) {
                if n.abs_diff(m) < best_n.abs_diff(best_m) {
                    best_n = n;
                    best_m = m;
                }
            }
        }
    }

    println!("{}", best_n.abs_diff(best_m));
}

