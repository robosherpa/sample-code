int getBinaryGap(int N)
{
    auto max_gap = 0;
    bool current_state = false;
    bool last_state = false;
    auto current_gap_length = 0;
    while(N > 0)
    {
        current_state = N%2;
        if (current_state == last_state)
        {
            current_gap_length++;
        }
        else
        {
            if (current_gap_length > max_gap)
            {
                max_gap = current_gap_length;
            }
            current_gap_length = 0;
        }
        N >>= 1;
    }
    return max_gap;
}