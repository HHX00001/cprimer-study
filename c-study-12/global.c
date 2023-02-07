//
// Created by stellar on 2023/2/2.
//

/**
 * 只有global可以用于同一程序中任意地方<br/>
 * inner只能用于所在的翻译单元中
 */

int global = 1;
static int inner = 2;