// NB: program takes an hour and a half to give an output

use std::collections::{HashMap, VecDeque};

type CoinList = HashMap<u32, u32>;

const COINS: [u32; 8] = [1, 2, 5, 10, 20, 50, 100, 200];
const TARGET: u32 = 200;

fn add_to_list(list: &mut CoinList, coin: u32) {
    if let Some(coin_count) = list.get_mut(&coin) {
        *coin_count += 1;
    } else {
        list.insert(coin, 1);
    }
}

fn get_list_sum(list: &CoinList) -> u32 {
    list.iter().map(|(coin_val, coin_count)| coin_val * coin_count).sum()
}

fn main() {
    let mut target_lists: Vec<CoinList> = Vec::new();
    let mut to_visit: VecDeque<CoinList> = VecDeque::from([HashMap::new()]);

    while let Some(current) = to_visit.pop_front() {
        for coin in COINS {
            let mut next = current.clone();
            add_to_list(&mut next, coin);
            match get_list_sum(&next) {
                TARGET => if !target_lists.contains(&next) { target_lists.push(next); },
                0..=TARGET => if !to_visit.contains(&next) { to_visit.push_back(next); },
                _ => (),
            };
        }
    }

    println!("{}", target_lists.len());
}

