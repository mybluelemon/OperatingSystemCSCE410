class FramePool {
private:
    /* -- DEFINE YOUR FRAME POOL DATA STRUCTURE(s) HERE. */
   unsigned long begin_frame;
   unsigned long size;
   unsigned long frame_number_store;
   unsigned int * bitmap;
   unsigned int * inacess_map;
   
public:
    /* Constructor FramePool
     *
     * Initializes the data structures needed for the management of this
     * frame pool. This function must be called before the paging system
     * is initialized.
     * _base_frame_no is the frame number at the start of the physical memory
     *                region that this frame pool manages.
     * _nframes is the number of frames in the physical memory region that this
     *          rame pool manages.
     * e.g. If _base_frame_no is 16 and _nframes is 4, this frame pool manages
     * physical frames numbered 16, 17, 18 and 19
     * _info_frame_no is the frame number (within the directly mapped region) of
     * the frame that should be used to store the management information of the
     * frame pool. However, if _info_frame_no is 0, the frame pool is free to
     * choose any frame from the pool itself to store management information.
     */
    FramePool(unsigned long _base_frame_no,
              unsigned long _nframes,
             unsigned long _info_frame_no);
    
    /* get_frame
     *
     * Allocates a frame from the frame pool. If there is a frame free to be allocated,
     * it returns the frame’snumber. If all frames in the frame pool are taken,
     * it returns 0xffffffff (this hexadecimal number conrresponds  tounsigned long(-1).
     * Notice that our machine is a 32 bit architecture)
     */
    unsigned long get_frame();
    
    /* release_frame
     *
     * Releases frame back to the frame pool.
     * The frame is identified by the frame number.
     * The function returns 0 on success and -1 on failure. Think about what failure
     * cases you need to cover. If not sure, ask in class!
     */
    unsigned long release_frame(unsigned long _frame_no);
    
    /* mark_inaccessible
     *
     * Mark the area of physical memory as inaccessible, i.e., not available for
     * consideration by get_frame/release_frame.
     •	* The arguments have the same semantics as in the constructor.
     •	* The function returns 0 on success and -1 on failure.
     */
    unsigned long  mark_inaccessible(unsigned long _base_frame_no,
                                     unsigned long _nframes);
};
