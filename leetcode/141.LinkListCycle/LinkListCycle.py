import pdb
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def hasCycle(self, head):
        try:
            v_set = set([])
            iter = head
            v_set.update([iter])
            while iter.next != None:
                iter = iter.next
                if iter not in v_set:
                    v_set.update([iter])
                else:
                    return True
            return False
        except:
            return False


if __name__ == "__main__":
    first = ListNode("first")
    head = ListNode("head")
    head.next = first

    su = Solution()
    if su.hasCycle(head):
        print("has Cycle")
    else:
        print("no Cycle")

    first.next = head
    if su.hasCycle(head):
        print("has Cycle")
    else:
        print("no Cycle")

