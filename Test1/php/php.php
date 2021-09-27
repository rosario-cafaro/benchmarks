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

try {
    $integers = explode("\n", file_get_contents("../../data/10k_integers.txt"));
} catch (Exception $e) {
    echo $e->getMessage();
}
quickSort($integers, 0, count($integers) - 1);

echo "First element: " . $integers[0] . "\nLast element: " . $integers[10000 - 1] . "\n";