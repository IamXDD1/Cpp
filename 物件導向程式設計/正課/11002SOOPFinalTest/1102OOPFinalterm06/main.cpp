/*
Copyright (c) 2022 Yen-Chen Chiu.
All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file.
 */
#include "ListMaker.h"

int main()
{
	vip_list::ListMaker list_maker = vip_list::ListMaker();

	list_maker.StartInput();
	list_maker.PrintList();

	return 0;
}
