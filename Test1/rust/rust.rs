use std::{
    fs::File,
    io::{prelude::*, BufReader},
    path::Path,
};

fn lines_from_file(filename: impl AsRef<Path>) -> Vec<String> {
    let file = File::open(filename).expect("no such file");
    let buf = BufReader::new(file);
    buf.lines()
        .map(|l| l.expect("Could not parse line"))
        .collect()
}

fn main() {
    let rows = lines_from_file("../../data/10k_integers.txt");
    let mut integers: [i32; 10000] = [0; 10000];
    
    let mut i: usize = 0;
    for row in rows {
        // println!("{:?}", row);
        integers[i] = row.parse::<i32>().unwrap();
        i += 1;
    }

    // print!("{} ", x);
    // integers.len()
    let quick_sort_high: usize = integers.len() - 1;
    quick_sort(&mut integers, 0, quick_sort_high as isize);

    println!("First element: {}\nLast element: {}\n", integers[0] as isize, integers[(integers.len() - 1)] as isize)
}

fn quick_sort<T: Ord>(arr: &mut [T], low: isize, high: isize) {
    if low < high {
        let p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

fn partition<T: Ord>(arr: &mut [T], low: isize, high: isize) -> isize {
    let pivot = high as usize;
    let mut store_index = low - 1;
    let mut last_index = high;

    loop {
        store_index += 1;
        while arr[store_index as usize] < arr[pivot] {
            store_index += 1;
        }
        last_index -= 1;
        while last_index >= 0 && arr[last_index as usize] > arr[pivot] {
            last_index -= 1;
        }
        if store_index >= last_index {
            break;
        } else {
            arr.swap(store_index as usize, last_index as usize);
        }
    }
    arr.swap(store_index as usize, pivot as usize);
    store_index
}