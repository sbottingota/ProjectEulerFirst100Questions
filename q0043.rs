const N_DIGITS: usize = 10;

type Digits = Vec<usize>;

// for each entry (n, m), the number formed by the combination of digits n, n+1, and n+2 must be divisible by m.
const CONSTRAINTS: [(usize, u32); 7] = [
    (1, 2),
    (2, 3),
    (3, 5),
    (4, 7),
    (5, 11),
    (6, 13),
    (7, 17)
];

fn passes_constraints(digits: &Digits) -> bool {
    for (n, m) in CONSTRAINTS {
        if (digits[n] * 100 + digits[n+1] * 10 + digits[n + 2]) as u32 % m != 0 {
            return false;
        }
    }
    true
}

fn unique_permutations(items: Digits) -> Vec<Digits> {
    if items.len() == 1 {
        vec![items]
    } else {
        let mut output: Vec<Digits> = vec![];

        // obtain a list of the unique elements
        let mut unique_items = items.clone();
        unique_items.sort();
        unique_items.dedup();
        for first in unique_items {
            let mut remaining_elements = items.clone();
            let index = remaining_elements.iter().position(|&x| x == first).unwrap();
            remaining_elements.remove(index);

            for mut permutation in unique_permutations(remaining_elements) {
                permutation.insert(0, first.clone());
                output.push(permutation);
            }
        }
        output
    }
}

fn get_value(digits: &Digits) -> u64 {
    let mut val: u64 = 0;
    for i in 0..digits.len() {
        val += digits[digits.len() - i - 1] as u64 * 10_u64.pow(i as u32);
    }
    val
}

fn main() {
    let mut sum: u64 = 0;
    for digits in unique_permutations((0..N_DIGITS).collect()) {
        if passes_constraints(&digits) {
            let i = get_value(&digits);
            // println!("{} passes constraints", i);
            sum += i;
        }
    }

    println!("{}", sum);
}

