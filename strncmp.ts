function strncmp(a: string, b: string, i: number): boolean {
  let a_after = a.substring(i);

  for (let j = 0; j < b.length; j++) {
    if (a_after[j] != b[j]) {
      return false;
    }
  }

  return true;
}
