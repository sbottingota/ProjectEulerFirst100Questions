const LIMIT: u64 = 1_000_000;
const TARGET_LEN: usize = 60;

fn fact(mut n: u64) -> u64 {
    let mut product = 1_u64;

    while n > 0 {
        product *= n;
        n -= 1;
    }

    product
}

fn sum_of_digits_fact(n: u64) -> u64 {
    n.to_string()
        .chars()
        .map(|c| fact(c.to_digit(10).unwrap().into()))
        .sum()
}

// return the number of non-repeating terms in a factorial digit chain
fn fact_chain_len(n: u64) -> usize {
    let mut chain = vec![n];

    loop {
        let next = sum_of_digits_fact(*chain.last().unwrap());

        // if the next value is already contained (i.e. a loop is found), return the length of the loop
        if chain.contains(&next) {
            return chain.len();
        } else {
            chain.push(next);
        }
    }
}

fn main() {
    let mut count = 0_u32;

    for i in 1..LIMIT {
        if fact_chain_len(i) == TARGET_LEN {
            count += 1;
        }
    }

    println!("{}", count);
}

