// ok well I wrote this code, but I realized that:
// a. it's too inefficient to compute for GRID_SIZE=21
// b. the sequence to which the answer belongs is A000984 (as was found from running this program for GRID_SIZE=3,4,5,etc.)

use std::collections::VecDeque;

const GRID_SIZE: u32 = 6;
const TARGET_SQUARE: (u32, u32) = (GRID_SIZE - 1, GRID_SIZE - 1);

fn get_moves_from_square((x, y): (u32, u32)) -> Vec<(u32, u32)> {
    let mut moves = Vec::new();

    if x < GRID_SIZE - 1 {
        moves.push((x + 1, y));
    }

    if y < GRID_SIZE - 1 {
        moves.push((x, y + 1));
    }

    moves
}

fn main() {
    let mut incomplete_paths: VecDeque<Vec<(u32, u32)>> = VecDeque::from([vec![(0, 0)]]);
    let mut completed_paths: Vec<Vec<(u32, u32)>> = Vec::new();

    while let Some(current_path) = incomplete_paths.pop_front() {
        for square in get_moves_from_square(current_path[current_path.len() - 1]) {
            let mut new_path = current_path.clone();
            new_path.push(square);

            if square == TARGET_SQUARE {
                completed_paths.push(new_path);
            } else {
                incomplete_paths.push_back(new_path);
            }
        }
    }

    println!("{}", completed_paths.len());
    // println!("{:?}", completed_paths);
}

