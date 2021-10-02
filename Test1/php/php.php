<?php

function partition(&$arr, $leftIndex, $rightIndex)
{
    $pivot = $arr[($leftIndex + $rightIndex) / 2];

    while ($leftIndex <= $rightIndex) {
        while ($arr[$leftIndex] < $pivot)
            $leftIndex++;
        while ($arr[$rightIndex] > $pivot)
            $rightIndex--;
        if ($leftIndex <= $rightIndex) {
            $tmp = $arr[$leftIndex];
            $arr[$leftIndex] = $arr[$rightIndex];
            $arr[$rightIndex] = $tmp;
            $leftIndex++;
            $rightIndex--;
        }
    }
    // echo implode(",", $arr) . " @pivot $pivot<br>";
    return $leftIndex;
}

function quickSort(&$arr, $leftIndex, $rightIndex)
{
    $index = partition($arr, $leftIndex, $rightIndex);
    if ($leftIndex < $index - 1)
        quickSort($arr, $leftIndex, $index - 1);
    if ($index < $rightIndex)
        quickSort($arr, $index, $rightIndex);
}

// All file in memory
// try {
//     $integers = explode("\n", file_get_contents("../../data/10k_integers.txt"));
// } catch (Exception $e) {
//     echo $e->getMessage();
// }


$file = new SplFileObject("../../data/10k_integers.txt");

// Loop until we reach the end of the file.
$i = 0;
while (!$file->eof()) {
    // Echo one line from the file.
    // echo $file->fgets();
    $integers[$i++] = $file->fgets();
}

// Unset the file to call __destruct(), closing the file handle.
$file = null;

quickSort($integers, 0, count($integers) - 1);

echo "First element: " . $integers[0] . "\nLast element: " . $integers[10000 - 1] . "\n";