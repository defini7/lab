function inArray(array1, array2) {
    let i, j, result = [];

    outer: for (j = 0; j < array1.length; j++) {
        for (i = 0; i < array2.length; i++) {
            if (array2[i].includes(array1[j])) {
                result.push(array1[j]);
                continue outer;
            }
        }
    }
    return result.sort();
}
