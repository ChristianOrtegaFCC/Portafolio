import { createClient } from '@supabase/supabase-js';

const supabaseUrl = 'https://zsaccgysojitjbwollov.supabase.co';
const supabaseAnonKey = 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InpzYWNjZ3lzb2ppdGpid29sbG92Iiwicm9sZSI6ImFub24iLCJpYXQiOjE3MzQzMDc0MzcsImV4cCI6MjA0OTg4MzQzN30._21GuUgbIgWfmCJc3UzZs0tZr6vu0ZE-IOvLedNLdKg';

export const supabase = createClient(supabaseUrl, supabaseAnonKey, {
  // This app only needs public reads, so we skip Supabase Auth session handling.
  accessToken: async () => supabaseAnonKey
});
