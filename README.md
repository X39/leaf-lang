# ![leaf-logo](logo-32px.png) leaf language

Leaf language is an in-development language that aims
to combine the best of Rust, C++ and C# into a single language
while providing more clear verbs for common keywords (eg. `unbound` instead of `static`).

The syntax is generated using [XCG](https://github.com/X39/XCG) and can be found in the `syntax` folder.

# How will it look like
**Disclaimer:**
Due to the nature of leaf, the following syntax might be outdated.

```
namespace leaf.example
{
    public class tree
    {
        public unbound i32 count
        {
            get { return count_backing; }
            set
            {
                count_backing = value;
                leaf.stdout.print($"count has changed to {count_backing}");
            }
        }
        private unbound i32 count_backing;
        
        
        local tree seed()
        {
            alias branch = tree;
            auto sapling = new stack branch();
            count++;
            return sapling;
        }
    }
}
```