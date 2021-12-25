/*
 * algorithm form hamming code
 * 1. get the position of all 'set' bits(1 bits).
 * 2. xor them to find which parity bits to flip.
 * 3. flip the parity bits based on set position bits of xored previous result.
 * 4. xor again it should give 0
 * 5. induce some random error
 * 6. xor again on set bits. it should give the position of error in binary
 */
function random_bit_array(len) {
	let arr = [];
	for (let i = 0; i < len; i++) {
		arr.push(Math.round(Math.random()));
	}
	return arr;
}

function return_set_index(arr) {
	let ind_arr = [];
	for (let x in arr) {
		if (arr[x])
			ind_arr.push(x);
	}
	return ind_arr;
}
function set_parity_bits(arr) {
	let parity_bit = return_set_index(arr).reduce((pv, cv) => pv ^ cv);
	let arrhol = parity_bit.toString(2).split('');
	console.log(arrhol);
	arrhol = arrhol.reverse();
	for (let x in arrhol) {
		let pos = 2 ** x;
		if (+arrhol[x]) {
			arr[pos] = (arr[pos])?0:1;
		}

	}
	console.log('set parity bits');
}


let arr = random_bit_array(150);
console.log(arr.length);
console.log(`array print: ${arr}`)
set_parity_bits(arr);
console.log(`after setting parity: xoring : ${return_set_index(arr).reduce((pv, cv) => pv ^ cv)}`)
let temp = Math.floor(Math.random() * 150)
arr[temp] = (arr[temp])?0:1;
console.log(`flipped ${temp} bit`);
console.log(`array print: ${arr}`)
console.log(`after flipping random bit: xoring : ${return_set_index(arr).reduce((pv, cv) => pv ^ cv)}`)
