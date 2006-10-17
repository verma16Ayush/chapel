config const numLocales = 1;

if (numLocales != 1) then
  halt("Multiple locales not yet supported");

// would like this to be the following, but it breaks about 20 tests:
//const LocaleDomain: domain(1) distributed(OnePer) = [0..numLocales);
const LocaleDomain = [0..numLocales);

class locale {
  const id: int;
}

def fwrite(outfile: file, loc: locale) {
  write("LOCALE", loc.id);
}

// would like this to be the following, but it breaks any 1D
// array sized-by-uint tests.
// const Locale: [loc in LocaleDomain] locale = locale(id = loc);
