# 1020_PA3
Implementing the menu to use a vector of Filter* was more difficult than
anticipated and we ran into several problems. When using the binary filter after creating one output image already, we would sometimes get a bad_alloc error. We are unsure of what actually caused the bad_alloc error but eventually we changed the way we were running the binary filter and it was fixed.

In driver.cpp, we couldn't figure out why the default case broke when we had a string or character input. We realized that this was because of two things. One, cin was failing to read because it wanted to take in an integer. Two, we weren't ever actually clearing out the cin buffer when we encountered a char or string. We fixed this by adding cin.clear and cin.ignore to skip the rest of the line.

In SepiaFilter, we forgot that we had to multiply the pixel values by 255 after calling inverse_gamma on the pixel
