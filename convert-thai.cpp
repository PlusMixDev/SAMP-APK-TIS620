void KingFramework::ConvertThaiImGui(char* out, const char* in, unsigned int len) {
    static const int table[128] = {
        // 80
        0,     0,     0,   0,     0,   0,   0,   0,
        0,   0,   0,     0,   0,     0,     0,     0,
        // 90
        0,     0,   0,   0,   0,   0,   0,   0,
        0,      0,   0,     0,   0,     0,     0,     0,
        // A0
        0x80b8e0,0x81b8e0,0x82b8e0,0x83b8e0,0x84b8e0,0x85b8e0,0x86b8e0,0x87b8e0,
        0x88b8e0,0x89b8e0,0x8ab8e0,0x8bb8e0,0x8cb8e0,0x8db8e0,0x8eb8e0,0x8fb8e0,
        // B0
        0x90b8e0,0x91b8e0,0x92b8e0,0x93b8e0,0x94b8e0,0x95b8e0,0x96b8e0,0x97b8e0,
        0x98b8e0,0x99b8e0,0x9ab8e0,0x9bb8e0,0x9cb8e0,0x9db8e0,0x9eb8e0,0x9fb8e0,
        // C0
        0xa0b8e0,0xa1b8e0,0xa2b8e0,0xa3b8e0,0xa4b8e0,0xa5b8e0,0xa6b8e0,0xa7b8e0,
        0xa8b8e0,0xa9b8e0,0xaab8e0,0xabb8e0,0xacb8e0,0xadb8e0,0xaeb8e0,0xafb8e0,
        // D0
        0xb0b8e0,0xb1b8e0,0xb2b8e0,0xb3b8e0,0xb4b8e0,0xb5b8e0,0xb6b8e0,0xb7b8e0,
        0xb8b8e0,0xb9b8e0,0xbab8e0,0       ,0       ,0       ,0       ,0xbfb8e0,
        // E0
        0x80b9e0,0x81b9e0,0x82b9e0,0x83b9e0,0x84b9e0,0x85b9e0,0x86b9e0,0x87b9e0,
        0x88b9e0,0x89b9e0,0x8ab9e0,0x8bb9e0,0x8cb9e0,0x8db9e0,0x8eb9e0,0x8fb9e0,
        // F0
        0x90b9e0,0x91b9e0,0x92b9e0,0x93b9e0,0x94b9e0,0x95b9e0,0x96b9e0,0x97b9e0,
        0x98b9e0,0x99b9e0,0x9ab9e0,0x9bb9e0
    };

    int count = 0;

    while (*in)
    {
        if (len && (count >= len)) break;

        // if (*in > 0x7e)
        if (*in > 0x80)
        {
            int v = table[(int)(0x7f & *in++)];
            if (!v)
                continue;

            *out++ = (char)v;
            *out++ = (char)(v >> 8);
            *out++ = (char)(v >> 16);

        }
        else // ASCII
            *out++ = *in++;

        count++;
    }

    *out = 0;
}