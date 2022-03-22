# ![leaf-logo](logo-32px.png) leaf language
*Parser for syntax was generated using [XCG](https://github.com/X39/XCG).
Related files are to be found inside the `syntax` folder.*

# Design Goals
Leaf is about a developers choices, about the toolbelt the dev wants (or has available)
for his frameworks, APIs or gigantic minification efforts.

Stuff like building shared-applications (as in service workers) and working with those should feel
as natural as possible.

There should never be an argument about "do we need this feature in the language really", as the
language itself has to support all that awesomeness we all do. If one thinks that return-type
directed methods should be possible, it has to be made possible. If one wants to use `async` and `await`,
then there shall be syntactic suggar for it. If one wants to create magnificent and beautiful frameworks with
`"<p>My <span class="fat">fancy</span> html framework"_html` then, again, it has to be possible.

Leaf should never block your goals as a language.
There may not be a suited framework (aka: written code) yet,
but the language will never attempt to hinder you in
building that framework.

# How will it look like
**Disclaimer:**
Due to the nature of leaf, the following syntax might be outdated.

```
namespace leaf.example
{
    public class Tree
    {
        public unbound i32 Count
        {
            get { return _countBacking; }
            set
            {
                _countBacking = value;
                leaf.stdout.print($"count has changed to {count_backing}");
            }
        }
        private unbound i32 _countBacking;
        
        
        local Tree Seed()
        {
            alias branch = tree;
            auto sapling = new stack branch();
            count++;
            return sapling;
        }
    }
    
    // Contracts are pseudo types that define a requirement of input types.
    // An input type does not have to implement a contract to make it feasable
    // for it.
    public contract CBranch
    {
        CEnumerable<RLeaf> Leafs { get; } 
    }
    
    // Interfaces are compile-time reflection pseudo-types,
    // allowing to create pseudo-methods
    public reflecting contract RLeaf
    {
        bool Equals(RLeaf t)
        {
            // for, if and all other control structures
            // do not require ()
            for field f of RLeaf
            {
                if f != f(t)
                    return false;
            }
            return true;
        }
    }
}
```

# How is the 