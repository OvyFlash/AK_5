#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>

#include <linux/types.h>

MODULE_AUTHOR("Shvachko Oleg");
MODULE_DESCRIPTION("Hello world");
MODULE_LICENSE("Dual BSD/GPL");

static uint count_hello_world = 1;
module_param(count_hello_world,uint,0);
MODULE_PARM_DESC(count_hello_world, "This parameter is responsible for number of hello world printed");

static int __init initter(void)
{
  uint i = 0;
  printk(KERN_INFO "Input %d\n", count_hello_world);

  if(count_hello_world == 0) 
  {
    printk(KERN_WARNING "You cannot enter 0");
  }
  else if(count_hello_world >=5 && count_hello_world <= 10) 
  {
    printk(KERN_WARNING "You should enter number below 5");
  } 
  else if(count_hello_world > 10) 
  {
    printk(KERN_ERR "The parameter is greater than 10");
    return -EINVAL;
  }

  for(i = 0; i < count_hello_world; i++){
    printk(KERN_INFO "Hello, world!\n");
  }
  return 0;
}

static void __exit exitter(void)
{

}

module_init(initter);
module_exit(exitter);
