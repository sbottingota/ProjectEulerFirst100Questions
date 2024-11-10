// N.B. takes quite long (around 18min on my device)

const DENOM_LIMIT: f64 = 1e6;
const IMMEDIATE_RIGHT: f64 = 3.0 / 7.0; // the fraction to the immediate right of the fraction we are trying to find.

fn main() {
    let mut best_num: f64 = 1.0;
    let mut best_frac: f64 = 0.0; // best_num/best_denom, to minimize calculatons

    let mut denom: f64 = 1.0;
    while denom <= DENOM_LIMIT {
        let num: f64 = (denom * IMMEDIATE_RIGHT).floor(); // very vague approximation
        if num / denom > best_frac && num / denom < IMMEDIATE_RIGHT {
            best_num = num;
            best_frac = num / denom;
        }


        denom += 1.0;
    }

    println!("{}", best_num);
}

